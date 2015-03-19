<div class="modal fade modal-z" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p><?php print t('Select builder')?></p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">
      <?php foreach($developers as $developer):?>
        <div class="col-xs-4">
          <ul>
            <li>
              <label class="checkbox-inline check-style">
                <input type="checkbox" class="Checkbox-developer" value="<?php print $developer['tid']?>">
                <?php print $developer['name']?>
              </label>
            </li>
          </ul>
        </div>
      <?php endforeach;?>
    </div>

    <div class="col-xs-12 modal-button">
      <a href="#href" id="select-developer" class="search-button modal-but" data-dismiss="modal">
        <?php print t('Select');?>
      </a>
    </div>
  </div>
</div>